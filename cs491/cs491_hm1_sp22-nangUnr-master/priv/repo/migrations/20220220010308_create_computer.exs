defmodule Cs491Hm1.Repo.Migrations.CreateComputer do
  use Ecto.Migration

  def change do
    create table(:computer) do
      add :brand, :string
      add :operating_systems_version, :integer

      timestamps()
    end
  end
end
